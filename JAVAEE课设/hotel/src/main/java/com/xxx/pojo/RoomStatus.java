package com.xxx.pojo;

import java.util.Date;

public class RoomStatus {
    private  Integer id;
    private String roomStyle;
    private String roomDoor;
    private String door;
    private String guestName;
    private String guestId;
    private String guestPhone;
    private String inTime;
    private String outTime;

    public RoomStatus() {
    }

    public RoomStatus(Integer id, String roomStyle, String roomDoor,String door,
                      String guestName, String guestId, String guestPhone, String inTime, String outTime) {
        this.id = id;
        this.roomStyle = roomStyle;
        this.roomDoor = roomDoor;
        this.door=door;
        this.guestName = guestName;
        this.guestId = guestId;
        this.guestPhone = guestPhone;
        this.inTime = inTime;
        this.outTime = outTime;
    }

    public String getDoor() {
        return door;
    }

    public void setDoor(String door) {
        this.door = door;
    }
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getRoomStyle() {
        return roomStyle;
    }

    public void setRoomStyle(String roomStyle) {
        this.roomStyle = roomStyle;
    }

    public String getRoomDoor() {
        return roomDoor;
    }

    public void setRoomDoor(String roomDoor) {
        this.roomDoor = roomDoor;
    }

    public String getGuestName() {
        return guestName;
    }

    public void setGuestName(String guestName) {
        this.guestName = guestName;
    }

    public String getGuestId() {
        return guestId;
    }

    public void setGuestId(String guestId) {
        this.guestId = guestId;
    }

    public String getGuestPhone() {
        return guestPhone;
    }

    public void setGuestPhone(String guestPhone) {
        this.guestPhone = guestPhone;
    }

    public String getInTime() {
        return inTime;
    }

    public void setInTime(String inTime) {
        this.inTime = inTime;
    }

    public String getOutTime() {
        return outTime;
    }

    public void setOutTime(String outTime) {
        this.outTime = outTime;
    }

    @Override
    public String toString() {
        return "RoomStatus{" +
                "id=" + id +
                ", roomStyle='" + roomStyle + '\'' +
                ", roomDoor='" + roomDoor + '\'' +
                ", guestName='" + guestName + '\'' +
                ", guestId='" + guestId + '\'' +
                ", guestPhone='" + guestPhone + '\'' +
                ", inTime='" + inTime + '\'' +
                ", outTime='" + outTime + '\'' +
                '}';
    }
}

