#pragma once
#include <stdint.h>

// This class follows the same memory layout as winrt::Windows::Devices::Radios::RadioState
enum class BluetoothRadioState : int32_t
{
	Unknown = 0,
	On = 1,
	Off = 2,
};