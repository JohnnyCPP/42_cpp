#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

namespace	pbook
{
	class	Contact
	{
	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:

		Contact();

		~Contact();

		Contact(const Contact& that);

		Contact&	operator=(const Contact& that);

		void		setFirstName(const std::string& firstName);
		std::string	getFirstName() const;

		void		setLastName(const std::string& lastName);
		std::string	getLastName() const;

		void		setNickname(const std::string& nickname);
		std::string	getNickname() const;

		void		setPhoneNumber(const std::string& phoneNumber);
		std::string	getPhoneNumber() const;

		void		setDarkestSecret(const std::string& darkestSecret);
		std::string	getDarkestSecret() const;
	};
}

#endif
