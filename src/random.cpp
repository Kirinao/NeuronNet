#include "random.h"


RandomNumbers:: RandomNumbers(unsigned long int s){
    if (s ==0){
        std::random_device rd;
        s = rd();
    }
    seed =s;
}



void RandomNumbers:: uniform_double(std::vector<double>& res, double lower, double upper) {
    std::uniform_real_distribution<> uniform(lower, upper);
    size_t limit (res.size());
    for (size_t i(0); i< limit; ++i){
        res[i] =uniform(rng);
    }
}

double RandomNumbers:: uniform_double(double lower, double upper){
    std::uniform_real_distribution<> uniform(lower, upper);
    return uniform(rng);
}


void RandomNumbers:: normal(std::vector<double>& res, double mean, double sd) {
    std::normal_distribution<> norm(mean, sd);
    size_t limit (res.size());
    for (size_t i(0); i< limit; ++i){
        res[i] =norm(rng);
    }
}

double RandomNumbers:: normal(double mean, double sd){
    std::normal_distribution<> norm(mean, sd);
    return norm(rng);
}

void RandomNumbers:: poisson(std::vector<int>& res, double mean){
    std::poisson_distribution<> pois(mean);
    size_t limit (res.size());
    for (size_t i(0); i< limit; ++i){
        res[i] =pois(rng);
    }
}
int RandomNumbers:: poisson(double mean){
    std::poisson_distribution<> pois(mean);
    return pois(rng);
}
