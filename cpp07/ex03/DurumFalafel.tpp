#ifndef DURUM_FALAFEL_TPP
# define DURUM_FALAFEL_TPP

# include "DurumFalafel.hpp"

template <int ChickpeaBalls>
const int DurumFalafel<ChickpeaBalls>::depth = ChickpeaBalls;

template <int ChickpeaBalls>
const char* DurumFalafel<ChickpeaBalls>::description(void)
{
    return "DurumFalafel wrapping ChickpeaBalls";
}

const int DurumFalafel<0>::depth = 0;

const char* DurumFalafel<0>::description(void)
{
    return "Base falafel (int)";
}

#endif
