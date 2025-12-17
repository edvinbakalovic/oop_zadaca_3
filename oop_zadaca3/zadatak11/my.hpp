#ifndef MY_HPP
#define MY_HPP

namespace my {

// Verzija sa predikatom
template <typename It, typename Compare>
void sort(It p, It k, Compare f) {
    for (It i = p; i != k; ++i) {
        for (It j = p; ; ++j) {
            It it = j;
            ++it; // sledeći element
            if (it == k) break; // došli smo do kraja
            if (!f(*j, *it)) {
                auto temp = *j;
                *j = *it;
                *it = temp;
            }
        }
    }
}

// Verzija bez predikata (default: manji -> veći)
template <typename It>
void sort(It p, It k) {
    sort(p, k, [](auto a, auto b) { return a < b; });
}

} // namespace my

#endif // MY_HPP

