package com.xxx.pojo;

public class Admin {
    private Integer id;
    private String adminName;
    private Integer adminNumber;
    private Integer adminPhone;
    private Integer adminIdNumber;
    private String adminAccounts;
    private String adminPassword;

    public Admin() {
    }

    public Admin(Integer id, String adminName, Integer adminNumber, Integer adminPhone, Integer adminIdNumber, String adminAccounts, String adminPassword) {
        this.id = id;
        this.adminName = adminName;
        this.adminNumber = adminNumber;
        this.adminPhone = adminPhone;
        this.adminIdNumber = adminIdNumber;
        this.adminAccounts=adminAccounts;
        this.adminPassword = adminPassword;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getAdminName() {
        return adminName;
    }

    public void setAdminName(String adminName) {
        this.adminName = adminName;
    }

    public Integer getAdminNumber() {
        return adminNumber;
    }

    public void setAdminNumber(Integer adminNumber) {
        this.adminNumber = adminNumber;
    }

    public Integer getAdminPhone() {
        return adminPhone;
    }

    public void setAdminPhone(Integer adminPhone) {
        this.adminPhone = adminPhone;
    }

    public Integer getAdminIdNumber() {
        return adminIdNumber;
    }

    public void setAdminIdNumber(Integer adminIdNumber) {
        this.adminIdNumber = adminIdNumber;
    }

    public String getAdminAccounts() {
        return adminAccounts;
    }

    public void setAdminAccounts(String adminAccounts) {
        this.adminAccounts = adminAccounts;
    }

    public String getAdminPassword() {
        return adminPassword;
    }

    public void setAdminPassword(String adminPassword) {
        this.adminPassword = adminPassword;
    }

    @Override
    public String toString() {
        return "Admin{" +
                "id=" + id +
                ", adminName='" + adminName + '\'' +
                ", adminNumber=" + adminNumber +
                ", adminPhone=" + adminPhone +
                ", adminIdNumber=" + adminIdNumber +
                ", adminAccounts=" + adminAccounts +
                ", adminPassword='" + adminPassword + '\'' +
                '}';
    }
}
