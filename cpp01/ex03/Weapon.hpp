#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
private:

	std::string	type;

public:

	Weapon();

	Weapon(const std::string& type);

	~Weapon();

	Weapon(const Weapon& that);

	Weapon&	operator=(const Weapon& that);

	void	setType(const std::string& type);
	const std::string&	getType() const;
};

#endif
