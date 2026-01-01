#include "Contact.hpp"

namespace	pbook
{

	Contact::Contact() :	firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("")
	{}

	Contact::~Contact()
	{}

	Contact::Contact(const Contact& that) :	firstName(that.firstName), lastName(that.lastName), nickname(that.nickname), phoneNumber(that.phoneNumber), darkestSecret(that.darkestSecret)
	{}

	Contact&	Contact::operator=(const Contact& that)
	{
		if (this != &that)
		{
			this->firstName = that.firstName;
			this->lastName = that.lastName;
			this->nickname = that.nickname;
			this->phoneNumber = that.phoneNumber;
			this->darkestSecret = that.darkestSecret;
		}
		return (*this);
	}

	void		Contact::setFirstName(const std::string& firstName)
	{
		this->firstName = firstName;
	}

	std::string	Contact::getFirstName() const
	{
		return (this->firstName);
	}

	void		Contact::setLastName(const std::string& lastName)
	{
		this->lastName = lastName;
	}

	std::string	Contact::getLastName() const
	{
		return (this->lastName);
	}

	void		Contact::setNickname(const std::string& nickname)
	{
		this->nickname = nickname;
	}

	std::string	Contact::getNickname() const
	{
		return (this->nickname);
	}

	void		Contact::setPhoneNumber(const std::string& phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}

	std::string	Contact::getPhoneNumber() const
	{
		return (this->phoneNumber);
	}

	void		Contact::setDarkestSecret(const std::string& darkestSecret)
	{
		this->darkestSecret = darkestSecret;
	}

	std::string	Contact::getDarkestSecret() const
	{
		return (this->darkestSecret);
	}

}
