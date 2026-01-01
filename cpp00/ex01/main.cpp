#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

static	std::string	CMD_ADD = "ADD";
static	std::string	CMD_SRCH = "SEARCH";
static	std::string	CMD_EXIT = "EXIT";

static	std::string	MSG_PROMPT = "Enter command (ADD, SEARCH, EXIT):";
static	std::string	MSG_FEEDBACK_ADD = "Executing contact insertion protocol...";
static	std::string	MSG_FEEDBACK_ADD_OK = "Contact insertion protocol executed successfully.";
static	std::string	MSG_FEEDBACK_SEARCH = "Executing contact query protocol...";
static	std::string	MSG_FEEDBACK_SEARCH_OK = "Contact query protocol executed successfully.";
static	std::string	MSG_REQUEST_INT = "Please insert contact index [1-";
static	std::string	MSG_REQUEST_INT_SUFFIX = "]:";
static	std::string	MSG_REQUEST = "Please insert field ";
static	std::string MSG_FIELD_NAME = "First name:";
static	std::string MSG_FIELD_LNAME = "Last name:";
static	std::string MSG_FIELD_NNAME = "Nickname:";
static	std::string MSG_FIELD_PHONE = "Phone number:";
static	std::string MSG_FIELD_SECRET = "Darkest secret:";
static	std::string	MSG_INVALID_CMD = "Invalid command.";
static	std::string	MSG_INVALID_INT = "Invalid index.";

static	int		toInteger(const std::string& input)
{
	std::stringstream	stream;
	int					n;

	stream.str(input);
	stream >> n;
	return (n);
}

static	bool	isNumber(const std::string& input)
{
	std::stringstream	stream;
	int					n;

	if (input.empty())
		return (false);
	stream.str(input);
	stream >> n;
	if (stream.fail() && stream.eof())
		return (false);
	return (true);
}

static	bool	isValid(const std::string& input, const std::size_t& contactCount)
{
	int	n;

	if (::isNumber(input) == false)
		return (false);
	n = toInteger(input);
	if (n <= 0)
		return (false);
	if (static_cast<std::size_t>(n) > contactCount)
		return (false);
	return (true);
}

static	void	searchContactByID(const pbook::PhoneBook& phoneBook, std::size_t id)
{
	pbook::Contact	contact;

	try
	{
		contact = phoneBook.getContact(id - 1);
		pbook::println(MSG_FIELD_NAME + contact.getFirstName());
		pbook::println(MSG_FIELD_LNAME + contact.getLastName());
		pbook::println(MSG_FIELD_NNAME + contact.getNickname());
		pbook::println(MSG_FIELD_PHONE + contact.getPhoneNumber());
		pbook::println(MSG_FIELD_SECRET + contact.getDarkestSecret());
		pbook::println(MSG_FEEDBACK_SEARCH_OK);
	}
	catch (const std::out_of_range& exception)
	{
		pbook::println(exception.what());
	}
}

static	void	searchContacts(const pbook::PhoneBook& phoneBook)
{
	const std::size_t&	contactCount = phoneBook.getContactCount();
	pbook::Contact		contact;
	std::string			input;
	std::size_t			id;

	pbook::println(MSG_FEEDBACK_SEARCH);
	phoneBook.printContacts();
	if (contactCount == 0)
		return ;
	input = "";
	pbook::print(MSG_REQUEST_INT + pbook::toString(contactCount) + MSG_REQUEST_INT_SUFFIX);
	std::getline(std::cin, input);
	while (::isValid(input, contactCount) == false)
	{
		pbook::println(MSG_INVALID_INT);
		pbook::print(MSG_REQUEST_INT + pbook::toString(contactCount) + MSG_REQUEST_INT_SUFFIX);
		std::getline(std::cin, input);
	}
	id = static_cast<std::size_t>(toInteger(input));
	searchContactByID(phoneBook, id);
}

static	std::string	requestField(const std::string& field)
{
	std::string		input;

	input = "";
	while (input == "")
	{
		pbook::print(MSG_REQUEST + field);
		std::getline(std::cin, input);
	}
	return (input);
}

static	void	addContact(pbook::PhoneBook& phoneBook)
{
	pbook::Contact	contact;

	pbook::println(MSG_FEEDBACK_ADD);
	contact.setFirstName(::requestField(MSG_FIELD_NAME));
	contact.setLastName(::requestField(MSG_FIELD_LNAME));
	contact.setNickname(::requestField(MSG_FIELD_NNAME));
	contact.setPhoneNumber(::requestField(MSG_FIELD_PHONE));
	contact.setDarkestSecret(::requestField(MSG_FIELD_SECRET));
	phoneBook.addContact(contact);
	pbook::println(MSG_FEEDBACK_ADD_OK);
}

int	main()
{
	pbook::PhoneBook	phoneBook;
	std::string			command;

	command = "";
	while (command != CMD_EXIT)
	{
		pbook::print(MSG_PROMPT);
		std::getline(std::cin, command);
		if (command == CMD_ADD)
			::addContact(phoneBook);
		else if (command == CMD_SRCH)
			::searchContacts(phoneBook);
		else if (command != CMD_EXIT)
			pbook::println(MSG_INVALID_CMD);
	}
	return (EXIT_SUCCESS);
}
