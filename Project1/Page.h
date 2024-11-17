#pragma once
#include <string>
class Page
{
private:
	std::string status;
	std::string posts;
public:
	void init();
	std::string getStatus() const;
	std::string getPosts() const;
	void clearPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);
};

