#include "PhoneBook.hpp"

namespace	pbook
{
	const std::size_t	PhoneBook::COLUMNS = 4;
	const std::size_t	PhoneBook::COL_WIDTH = 10;

	const std::string	PhoneBook::HEAD_1 = "Index";
	const std::string	PhoneBook::HEAD_2 = "First Name";
	const std::string	PhoneBook::HEAD_3 = "Last Name";
	const std::string	PhoneBook::HEAD_4 = "Nickname";

	const std::string	PhoneBook::MSG_OUTOF_B = "Index out of bounds";
	const std::string	PhoneBook::MSG_NO_CONT = "The book is empty.";

	std::string	toString(const std::size_t n)
	{
		std::stringstream	stream;
		stream << n;
		return (stream.str());
	}

	void	println(const std::string& str)
	{
		std::cout << str << std::endl;
	}

	void	print(const std::string& str)
	{
		std::cout << str;
	}

	void	PhoneBook::shiftContacts()
	{
		std::size_t	i;

		i = this->contactCount;
		if (this->contactCount == CONT_MAX)
			i --;
		while (0 < i)
		{
			this->contacts[i] = this->contacts[i - 1];
			i --;
		}
	}

	std::string	PhoneBook::truncate(const std::string& str) const
	{
		std::size_t	pos;
		std::size_t	count;
	
		pos = 0;
		count = COL_WIDTH - 1;
		if (str.length() > COL_WIDTH)
			return (str.substr(pos, count) + ".");
		return (str);
	}

	std::string	PhoneBook::getRowPart(const std::string& str) const
	{
		std::string	truncated;
		std::string	rowPart;
		std::size_t	spaces;
		std::size_t	i;
	
		truncated = truncate(str);
		rowPart = '|';
		spaces = COL_WIDTH - truncated.length();
		i = 0;
		while (i ++ < spaces)
			rowPart += ' ';
		rowPart += truncated;
		return (rowPart);
	}

	void	PhoneBook::printRow(const std::string* strList) const
	{
		std::string	row;
		std::size_t	i;

		if (!strList)
			return ;
		row = "";
		i = 0;
		while (i < COLUMNS)
			row += getRowPart(strList[i ++]);
		row += '|';
		println(row);
	}

	void	PhoneBook::printContact(const std::size_t i) const
	{
		try
		{
			const Contact&	contact = getContact(i);
			std::string	row[COLUMNS];

			row[0] = toString(i + 1);
			row[1] = contact.getFirstName();
			row[2] = contact.getLastName();
			row[3] = contact.getNickname();
			printRow(row);
		}
		catch (const std::out_of_range& exception)
		{
			println(exception.what());
		}
	}

	void	PhoneBook::printSeparator() const
	{
		std::size_t	i;
		std::size_t	j;
	
		i = 0;
		while (i < COLUMNS)
		{
			std::cout << '|';
			j = 0;
			while (j < COL_WIDTH)
			{
				std::cout << '-';
				j ++;
			}
			i ++;
		}
		std::cout << '|' << std::endl;
	}

	void	PhoneBook::printHeader() const
	{
		std::string	row[COLUMNS];

		row[0] = HEAD_1;
		row[1] = HEAD_2;
		row[2] = HEAD_3;
		row[3] = HEAD_4;
		printRow(row);
	}

	PhoneBook::PhoneBook() :	contactCount(0)
	{}

	PhoneBook::~PhoneBook()
	{}

	PhoneBook::PhoneBook(const PhoneBook& that) :	contactCount(that.contactCount)
	{
		std::size_t	i;

		i = 0;
		while (i < that.contactCount)
		{
			this->contacts[i] = that.contacts[i];
			i ++;
		}
	}

	PhoneBook&	PhoneBook::operator=(const PhoneBook& that)
	{
		std::size_t	i;

		if (this != &that)
		{
			i = 0;
			while (i < that.contactCount)
			{
				this->contacts[i] = that.contacts[i];
				i ++;
			}
			this->contactCount = that.contactCount;
		}
		return (*this);
	}

	void	PhoneBook::addContact(const Contact& contact)
	{
		if (this->contactCount)
			this->shiftContacts();
		this->contacts[0] = contact;
		if (this->contactCount < CONT_MAX)
			this->contactCount ++;
	}

	// @throws std::out_of_range
	const Contact&	PhoneBook::getContact(const std::size_t index) const
	{
		if (index >= contactCount)
			throw std::out_of_range(MSG_OUTOF_B);
		return (this->contacts[index]);
	}

	const std::size_t&	PhoneBook::getContactCount() const
	{
		return (this->contactCount);
	}

	void	PhoneBook::printContacts() const
	{
		std::size_t	i;
	
		if (!contactCount)
		{
			println(MSG_NO_CONT);
			return ;
		}
		printHeader();
		printSeparator();
		i = 0;
		while (i < contactCount)
		{
			printContact(i);
			i ++;
		}
	}
}
