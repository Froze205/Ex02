#include "Page.h"
#include <string> 
void Page::init()
{
	this->status = "";
	this->posts = "";
}
std::string Page::getStatus() const
{
	return this->status;
}
std::string Page::getPosts() const
{
	return this->posts;
}
void Page::clearPage()
{
	this->posts = "";
}
void Page::setStatus(const std::string new_status)
{
	this->status = new_status;
}
void Page::addLineToPosts(const std::string new_line)
{
	this->posts += new_line + "\n";
}


