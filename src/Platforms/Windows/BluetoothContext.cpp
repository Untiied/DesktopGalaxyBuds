#include "BluetoothContext.h"
#include <iostream>

WinBuds::BluetoothContext::BluetoothContext()
{
	winrt::init_apartment();
}

WinBuds::BluetoothContext::~BluetoothContext()
{
}

bool WinBuds::BluetoothContext::IsBluetoothEnabled() {
	WinRadio::RadioState radio_state = GetBluetoothRadioState();

	if (radio_state == WinRadio::RadioState::Off)
		return false;

	return true;
}

bool WinBuds::BluetoothContext::IsBluetoothLESupported()
{
	WinTooth::BluetoothAdapter bluetooth_adapter = WinTooth::BluetoothAdapter::GetDefaultAsync().get();

	return bluetooth_adapter.IsLowEnergySupported();
}

bool WinBuds::BluetoothContext::SetBluetoothState(BluetoothRadioState state)
{
	WinRadio::Radio bluetooth_radio = GetBluetoothRadio();
	// We take our BluetoothRadioState and cast it to windows's state. 
	// We can do this because our id's follow theirs.
	auto result = bluetooth_radio.SetStateAsync((WinRadio::RadioState)state).get();

	if (result == WinRadio::RadioAccessStatus::Allowed)
		return true;

	return false;
}

// @TODO: PAIRING IS NOT IMPLEMENTED
// We will use the Device Enumeration and Pairing APIs for it.
void WinBuds::BluetoothContext::QueryForDevices() {
	if (IsBluetoothLESupported()) {
		WinTooth::BluetoothAdapter bluetooth_adapter = WinTooth::BluetoothAdapter::GetDefaultAsync().get();

		// If we are able to get ManufacturerData using the samsung bluetooth hexID then continue.
		// This doesn't guarrentee it's the galaxy buds though.
		WinTooth::Advertisement::BluetoothLEManufacturerData samsung_data_filter;
		samsung_data_filter.CompanyId(0x0075);

		WinTooth::Advertisement::BluetoothLEAdvertisementWatcher bluetooth_watcher;
		bluetooth_watcher.AdvertisementFilter().Advertisement().ManufacturerData().Append(samsung_data_filter);
		bluetooth_watcher.ScanningMode(WinTooth::Advertisement::BluetoothLEScanningMode::Active);

		uint64_t bluetooth_device_address_long;

		// Lambda expression for handling the event.
		bluetooth_watcher.Received([this, bluetooth_device_address_long](WinTooth::Advertisement::BluetoothLEAdvertisementWatcher watcher, WinTooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs advertisment_event) mutable {
			bluetooth_device_address_long = advertisment_event.BluetoothAddress();
			
			std::cout << "Found a potential device!" << std::endl;

			WinTooth::BluetoothLEDevice samsung_device = WinTooth::BluetoothLEDevice::FromBluetoothAddressAsync(advertisment_event.BluetoothAddress()).get();
			if (samsung_device != NULL) {
				std::cout << samsung_device.Name().c_str() << std::endl;
				watcher.Stop();
			}
		});

		std::cout << "Listening for devices.\n" << std::endl;
		bluetooth_watcher.Start();

		//Lock the thread while we wait on a recieved signal.. Should use a mutex but for now we use a while loop.
		while (bluetooth_watcher.Status() == WinTooth::Advertisement::BluetoothLEAdvertisementWatcherStatus::Started) {

		}


	}
}

///////////////////////////////////////////////////////////////////////////////////// PRIVATE /////////////////////////////////////////////////////////////////

WinRadio::RadioState WinBuds::BluetoothContext::GetBluetoothRadioState()
{
	return GetBluetoothRadio().State();
}

WinRadio::Radio WinBuds::BluetoothContext::GetBluetoothRadio()
{
	auto radios = WinRadio::Radio::GetRadiosAsync().get();

	for (uint32_t i = 0; i < radios.Size(); i++)
	{
		if (radios.GetAt(i).Kind() == WinRadio::RadioKind::Bluetooth) {
			return radios.GetAt(i);
		}
	}

	// @TODO: Add debugging.
	return NULL;
}
