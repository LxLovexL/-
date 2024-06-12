package com.xxx.pojo;

public class Guest {
    private Integer id;
    private String guestName;
    private Integer guestAge;
    private Integer guestPhone;
    private Integer guestIdNumber;

    public Guest() {
    }

    public Guest(Integer id, String guestName, Integer guestAge, Integer guestPhone, Integer guestIdNumber) {
        this.id = id;
        this.guestName = guestName;
        this.guestAge = guestAge;
        this.guestPhone = guestPhone;
        this.guestIdNumber = guestIdNumber;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getGuestName() {
        return guestName;
    }

    public void setGuestName(String guestName) {
        this.guestName = guestName;
    }

    public Integer getGuestAge() {
        return guestAge;
    }

    public void setGuestAge(Integer guestAge) {
        this.guestAge = guestAge;
    }

    public Integer getGuestPhone() {
        return guestPhone;
    }

    public void setGuestPhone(Integer guestPhone) {
        this.guestPhone = guestPhone;
    }

    public Integer getGuestIdNumber() {
        return guestIdNumber;
    }

    public void setGuestIdNumber(Integer guestIdNumber) {
        this.guestIdNumber = guestIdNumber;
    }

    @Override
    public String toString() {
        return "Guest{" +
                "id=" + id +
                ", guestName='" + guestName + '\'' +
                ", guestAge=" + guestAge +
                ", guestPhone=" + guestPhone +
                ", guestIdNumber=" + guestIdNumber +
                '}';
    }
}
