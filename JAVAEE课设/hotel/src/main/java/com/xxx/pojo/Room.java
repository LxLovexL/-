package com.xxx.pojo;

public class Room {
    private Integer id;
    private String style;
    private String door;
    private Integer price;
    private String others;
    private Integer status;

    public Room() {
    }

    public Room(Integer id, String style, String door, Integer price, String others, Integer status) {
        this.id = id;
        this.style = style;
        this.door = door;
        this.price = price;
        this.others = others;
        this.status = status;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getStyle() {
        return style;
    }

    public void setStyle(String style) {
        this.style = style;
    }

    public String getDoor() {
        return door;
    }

    public void setDoor(String door) {
        this.door = door;
    }

    public Integer getPrice() {
        return price;
    }

    public void setPrice(Integer price) {
        this.price = price;
    }

    public String getOthers() {
        return others;
    }

    public void setOthers(String others) {
        this.others = others;
    }

    public Integer getStatus() {
        return status;
    }

    public void setStatus(Integer status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "Room{" +
                "id=" + id +
                ", style='" + style + '\'' +
                ", door=" + door +
                ", price=" + price +
                ", others='" + others + '\'' +
                ", status=" + status +
                '}';
    }
}
