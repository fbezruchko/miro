#include "Robot.h"

using namespace miro;

//========================================== C
Robot::Robot(byte *PWM_pins, byte *DIR_pins) : chassis(PWM_pins, DIR_pins)
{
	this->_device_count = 0;
}

#if defined(ENCODERS_ON)
//========================================== C
Robot::Robot(byte *PWM_pins, byte *DIR_pins, byte *ENCODER_pins) : chassis(PWM_pins, DIR_pins, ENCODER_pins)
{
	this->_device_count = 0;
}
#endif // ENCODERS_ON

//========================================== D
Robot::~Robot()
{
}

//========================================== Sync
void Robot::Sync()
{
	this->chassis.Sync();
	for (char i = this->_device_count-1; i >= 0; --i) this->_devices[i]->Sync();
}

//========================================== attachDevice
int Robot::attachDevice(Device *dev)
{
	if (dev == nullptr) return -1;
	if (this->_device_count == ROBOT_MAX_DEVICES) return -3;
	
	this->_devices[this->_device_count] = dev;
	this->_device_count++;

	return 0;
}

//========================================== dettachDevice
int Robot::dettachDevice(Device *dev)
{
	if (dev == nullptr) return -1;

	for (char d = this->_device_count-1; d >= 0; --d)
	{
		if (this->_devices[d] == dev) return this->dettachDevice(d);
	}

	return -2; // Device not found
}

//========================================== dettachDevice
int Robot::dettachDevice(byte DeviceIndex)
{
	if (DeviceIndex > this->_device_count) return -2;

	for (char d = DeviceIndex; d < this->_device_count; d++) this->_devices[d] = this->_devices[d + 1];
	
	this->_device_count--;

	return 0;
}

//========================================== GetDeviceByIndex
Device* Robot::getDeviceByIndex(byte DeviceIndex)
{
    if ((DeviceIndex >= 0) && (DeviceIndex < this->_device_count))
    {
        return this->_devices[DeviceIndex];
    }
    else return nullptr;
}

//========================================== GetDeviceCount
byte Robot::getDeviceCount() { return this->_device_count; }
