    //assumption:more that 5 seats cannot be reserved 
    if (f2->getReservedSeats() >= 5) {
        throw Mystring("reservatin limit ");
        return;
    }
    cout << "Enter passenger name: ";
    Mystring pname;
    cin >> pname;
    int newResId;
    if (reservations.empty()) {
        newResId = 1;
    }
    else {
        Reservation r1 = reservations.back();
        int lastId = r1.get_reservation_Id();
        newResId = lastId + 1;
    }
    reservations.push(Reservation(newResId, f1->getFlightId(), iid, pname));
    f2->reserveSeat();
    Logger::getInstance().log("reservation done.");
    cout << "Booking successful with r_id " << newResId << endl;
}
