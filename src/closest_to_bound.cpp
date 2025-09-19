#include "../include/closest_to_bound.h"
#include <stdexcept>


using namespace std;
using ll = long long;

ll closest_to_bound(const ll divider, const ll bound){
    if (divider <= 0 || bound <= 0) {
        throw invalid_argument("Параметры должны быть положительными числами!");
    }
    
    ll result = bound - (bound % divider);
    if (result <= 0){
        throw runtime_error("Невоможно найти N > 0, удовлетворяющее условиям!");
    }
    return bound - (bound % divider);
}