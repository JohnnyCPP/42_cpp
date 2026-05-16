#ifndef DURUM_FALAFEL_HPP
# define DURUM_FALAFEL_HPP

// recursive falafel wrapper
template <int ChickpeaBalls>
struct DurumFalafel
{
    typedef typename DurumFalafel<ChickpeaBalls - 1>::Type Type;
    static const int depth;
    static const char* description(void);
};

// specialization for base case (no ChickpeaBalls left)
template <>
struct DurumFalafel<0>
{
    typedef int Type;
    static const int depth;
    static const char* description(void);
};

# include "DurumFalafel.tpp"

#endif
