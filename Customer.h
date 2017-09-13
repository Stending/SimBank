#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    protected :
        double _arrivalTime;

    public :
        Customer(double _arrivalTime);
        double arrivalTime() const;
};

#endif
