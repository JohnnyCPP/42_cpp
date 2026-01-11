┌─────────────────┐       ┌─────────────────┐
│  IMateriaSource │<------│  MateriaSource  │
│  (Interface)    │       │  (Concrete)     │
└─────────────────┘       └─────────────────┘
        ↑ learns                 ↑ creates
        │                        │
┌─────────────────┐       ┌─────────────────┐
│   AMateria      │<------│  Ice / Cure     │
│  (Abstract)     │       │  (Concrete)     │
└─────────────────┘       └─────────────────┘
        ↑ used by                ↑ cloned by
        │                        │
┌─────────────────┐       ┌─────────────────┐
│   ICharacter    │<------│   Character     │
│  (Interface)    │       │  (Concrete)     │
└─────────────────┘       └─────────────────┘

# abstract class

- A class that cannot be instantiated
- Can have both Concrete Methods and Abstract Methods
- Provides a partial implementation that derived classes complete

# interface

- A pure abstract class. All methods are pure virtual, except the destructor
- Contains only pure virtual methods
- Defines a contract that implementing classes must fulfill
