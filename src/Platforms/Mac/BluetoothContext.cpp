#include "BluetoothContext.h"

WinBuds::BluetoothContext::BluetoothContext()
{

}

WinBuds::BluetoothContext::~BluetoothContext()
{
}

bool WinBuds::BluetoothContext::IsBluetoothEnabled() {
    return false;
}

bool WinBuds::BluetoothContext::SetBluetoothState(BluetoothRadioState state)
{
    return false;
}

void WinBuds::BluetoothContext::QueryForDevices() {

}
