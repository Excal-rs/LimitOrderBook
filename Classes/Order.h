#pragma once

class Order {
    public:
        Order(int user, double price, int qty, bool isBuy) : orderID(nextOrderID++), userID(user), price(price), quantity(qty), isBuyOrder(isBuy) {
            // Constructor body (if needed)
        }
        ~Order() = default;

        int getOrderID() const { return orderID; }
        int getUserID() const { return userID; }
        double getPrice() const { return price; }
        int getQuantity() const { return quantity; }
        bool getIsBuyOrder() const { return isBuyOrder; }

    private:
        int orderID;
        int userID;
        
        double price;
        int quantity;
        
        bool isBuyOrder;

        static int nextOrderID;
};