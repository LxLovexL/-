package com.xxx.mapper;

import com.xxx.pojo.Admin;
import org.apache.ibatis.annotations.Param;

public interface AdminMapper {

    //登录查询

    Admin selctaccounts(@Param("adminAccounts") String adminAccounts,
                @Param("adminPassword") String adminPassword);

}
