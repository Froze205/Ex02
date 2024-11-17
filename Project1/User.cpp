#include "User.h"
#include <string> 
void User::init(unsigned int id, const std::string username, unsigned int age)
{
    this->id = id;
    this->username = username;
    this->age = age;
    this->devices.init();
}
void User::clear()
{
    this->devices.clear();
}
unsigned int User::getID() const
{
    return this->id;
}
std::string User::getUserName() const
{
    return this->username;
}
unsigned int User::getAge() const
{
    return this->age;
}
DevicesList& User::getDevices()
{
    return this->devices;
}
void User::addDevice(const Device& newDevice)
{
    this->devices.add(newDevice);
}
bool User::checkIfDevicesAreOn() const
{
    DeviceNode* current = this->devices.get_first();
    while (current != nullptr)
    {
        if (!(current->get_data().isActive()))
        {
            return false;
        }
        current = current->get_next();
    }
    return true;
}

