#ifndef CALCULATE_ADD_HEADER
#define CALCULATE_ADD_HEADER

template <typename T, typename U>
auto Add(T t, U u) -> decltype(t + u){
    return t + u;
}
#endif // ! CALCULATE_ADD_HEADER