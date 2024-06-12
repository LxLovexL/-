package com.xxx.web;

import com.xxx.mapper.AdminMapper;
import com.xxx.pojo.Admin;
import com.xxx.util.SqlSessionFactoryUtils;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    //接收用户账号和密码
        String  account=request.getParameter("account");
        String password=request.getParameter("password");
       // username=new String(username.getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);

        SqlSessionFactory sqlSessionFactory= SqlSessionFactoryUtils.getSqlSessionFactory();

        SqlSession sqlSession = sqlSessionFactory.openSession();
        AdminMapper adminMapper = sqlSession.getMapper(AdminMapper.class);
        Admin admin=adminMapper.selctaccounts(account,password);
        sqlSession.close();

        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        //判断是否存在
        if (admin!=null){
            //存储数据
            //请求转发
            request.getRequestDispatcher("/RoomSelectAll").forward(request, response);
        }else {
           response.sendRedirect("http://localhost:8080/hotel/loginWorry.html");
        }

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
