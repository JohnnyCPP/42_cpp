#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstddef>
# include <stdexcept>
# include <string>
# include <iostream>
# include <sstream>

namespace	pbook
{
	std::string	toString(const std::size_t n);
	void		println(const std::string& str);
	void		print(const std::string& str);

	class	PhoneBook
	{
	public:

		enum
		{
			CONT_MAX = 8
		};

		static const std::size_t	COLUMNS;
		static const std::size_t	COL_WIDTH;

		static const std::string	HEAD_1;
		static const std::string	HEAD_2;
		static const std::string	HEAD_3;
		static const std::string	HEAD_4;

		static const std::string	MSG_OUTOF_B;
		static const std::string	MSG_NO_CONT;

	private:

		Contact		contacts[CONT_MAX];
		std::size_t	contactCount;

		void		shiftContacts();

		std::string	truncate(const std::string& str) const;
		std::string	getRowPart(const std::string& str) const;
		void		printRow(const std::string* strList) const;
		void		printContact(const std::size_t i) const;
		void		printSeparator() const;
		void		printHeader() const;
	
	public:

		PhoneBook();

		~PhoneBook();

		PhoneBook(const PhoneBook& that);

		PhoneBook&	operator=(const PhoneBook& that);

		void			addContact(const Contact& contact);
		const Contact&	getContact(const std::size_t index) const;
		const std::size_t&	getContactCount() const;
		void			printContacts() const;
	};
}

#endif
