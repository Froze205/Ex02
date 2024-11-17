#include "Profile.h"
void Profile::init(const User owner)
{
	this->owner = owner;
	this->page.init();
	this->friends.init();
}
void Profile::clear()
{
	this->page.clearPage();
	this->friends.clear();
}
User Profile::getOwner() const
{
	return this->owner;
}
void Profile::setStatus(const std::string new_status)
{
	this->page.setStatus(new_status);
}
void Profile::addPostToProfilePage(const std::string post)
{
	this->page.addLineToPosts(post);
}
void Profile::addFriend(const User friend_to_add)
{
	this->friends.add(friend_to_add);
}
std::string Profile::getPage() const
{
	std::string result = "Status: " + this->page.getStatus() + "\n";
	result += "*******************\n";
	result += "*******************\n"; 
	result += this->page.getPosts();
	return result;
}
std::string Profile::getFriends() const
{
	std::string list = "";
	UserNode* current = this->friends.get_first();
	while (current != nullptr)
	{
		list += current->get_data().getUserName();
		current = current->get_next();
		if (current != nullptr)
		{
			list += ",";
		}
	}
	return list;
}
std::string Profile::getFriendsWithSameNameLength() const
{
	int owner_length = this->owner.getUserName().length();
	std::string list = "";
	UserNode* current = this->friends.get_first();
	while (current != nullptr)
	{
		User friend_name = current->get_data();
		if (friend_name.getUserName().length() == owner_length)
		{
			if (!list.empty())
				list += ",";
			list += friend_name.getUserName();
		}
		current = current->get_next();
	}
	return list;
}

