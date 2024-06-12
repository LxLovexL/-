package com.xxx.web;

import com.xxx.pojo.Room;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.List;

@WebServlet("/changeSelectServlet")
public class changeSelectServlet extends HttpServlet {
    RoomService service=new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String door = request.getParameter("door");
        List<Room> rooms=service.selectAll();
        request.setAttribute("rooms",rooms);
        request.setAttribute("doors",door);
        request.getRequestDispatcher("/changeRoom.jsp").forward(request,response);
    }


    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
