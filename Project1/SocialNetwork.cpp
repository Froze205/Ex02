#include "SocialNetwork.h"
#include <string>

void SocialNetwork::init(std::string networkName, int minAge) 
{
	this->networkName = networkName;
	this->minAge = minAge;

}
void SocialNetwork::clear() 
{
	profiles.clear();
}
std::string SocialNetwork::getNetworkName() const {
	return networkName;
}
int SocialNetwork::getMinAge() const {
	return minAge;
}
bool SocialNetwork::addProfile(Profile profile_to_add) {
	if (profile_to_add.getOwner().getAge() < minAge)
		return false;
	profiles.add(profile_to_add);
	return true;
}
std::string SocialNetwork::getWindowsDevices() const
{
    std::string result = "";
    ProfileNode* curr = this->profiles.get_first();

    while (curr != nullptr)
    {
        Profile currentProfile = curr->get_data();
        User currentUser = currentProfile.getOwner();
        DevicesList list = currentUser.getDevices();
        DeviceNode* currDevice = list.get_first();

        while (currDevice != nullptr)
        {
            Device device = currDevice->get_data();
            std::string os = device.getOS();

            if (os.find("Windows") != std::string::npos)
            {
                std::string deviceData = "[" + std::to_string(device.getID()) + ", " + os + "]";

                if (!result.empty())
                {
                    result += ", ";
                }
                result += deviceData;
            }

            currDevice = currDevice->get_next();
        }

        curr = curr->get_next();
    }

    return result;
}
