#include<iostream>
#include <vector>
#include <time.h> // For time data types (if needed)


// Interface for payment details
class PaymentDetails {
public:
    virtual ~PaymentDetails() {} // Virtual destructor for proper cleanup in inheritance
    virtual std::string getCardholderName() const = 0;
    virtual void setCardholderName(const std::string& name) = 0;
    virtual PaymentDetails* clone()=0;
};

// Credit card payment details
class CreditCardPaymentDetail : public PaymentDetails {
 private:
    std::string cardHolderName;
    std::string cardNumber;
    std::string expirationDate;
    std::string securityCode;
public:

    // Implement methods from PaymentDetails
    std::string getCardholderName() const override { return cardHolderName; }
    void setCardholderName(const std::string& name) override { cardHolderName = name; }
    CreditCardPaymentDetail(CreditCardPaymentDetail& obj)
    {
        //code will be here
    }
    //other setter/getter methods will be here
    PaymentDetails* clone() override { return new CreditCardPaymentDetail(*this); }
};

// PayPal payment details
class PayPalPaymentDetail : public PaymentDetails {
public:
    std::string emailAddress;
    std::string cardHolderName;
    // Implement methods from PaymentDetails
    std::string getCardholderName() const override { return cardHolderName; } 
    void setCardholderName(const std::string& name) override { cardHolderName = name; }  
    PayPalPaymentDetail(PayPalPaymentDetail& obj)
    {
        //code will be here
    }
    

    //other setter/getter methods will be here
    PaymentDetails* clone() override { return new PayPalPaymentDetail(*this); }
};

// Class representing a ticket
class Ticket {
private:
    std::string ticketID;
    FlightDetails flight;
    std::string seatNumber;
    int maxKG;
    float price;
    std::string typeOfTicket;
public:
    void cancelTicket();
    // Add methods as setter/getter and other needed (e.g., getDetails())
};

// Class representing a user
class User {
private:
    std::string userID;
    std::string password;
    std::string loginStatus;
    std::string email;
public:
    // Add methods as setter/getter and other needed (e.g., verifyLogin(), register())
};

// Customer class inheriting from User
class Customer : public User {
private:
    std::string customerName;
    std::string address;
    std::string creditCardInfo;
    float accountBalance;
    Ticket ticket;
    FlightDetails flightDetails;
public:
    //Add methods as setter/getter and other needed (e.g., updateProfile(),login())
};

// Singleton class representing the administrator
class Administrator {
private:
    static Administrator* instance;
    List<ScheduledFlights> FlightList;
    List<User> user;
    Administrator() {} // Private constructor for singleton pattern
    Administrator(Administrator&);
    Administrator& operator=(Administrator&);
public:
    static Administrator* getInstance() {
        if (!instance)
        {
            instance = new Administrator();
        }
        return instance;
    }
    void addFlight(ScheduledFlights flight);
    ScheduledFlights search(int flightnumber);
    // Add other methods if needed
};
class Airport {
private:
    std::string airportName;
    List<int> ScheduledFlightsID;
public:
    //Add methods as setter/getter and other if needed
};
// Class representing scheduled flights
class ScheduledFlights {
private:
    int flightNumber;
    std::string sirlineName;
    time departuretime;
    date departuredate;
    time arrivaltime;
    date arrivaldate;
    int flightcapacity;
    float economyPrice;
    float businessPrice;
public:
    //Add methods as setter/getter
};

// Class representing flight details 
class FlightDetails {
private:
    std::string flightID;  
    std::string source;
    std::string destination;
    std::string customerID;
public:
    void displayFlightDetail();
    //Add methods as setter/getter and other if needed
};

// Class representing a seat (possibly associated with FlightDetails)
class Seat : public FlightDetails {
private:
    int seatId;
    std::string typeOfSeat;
public:
    //Add methods as setter/getter and other if needed
};
