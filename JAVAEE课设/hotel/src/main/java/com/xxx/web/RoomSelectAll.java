package com.xxx.web;

import com.xxx.pojo.Room;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.List;

@WebServlet("/RoomSelectAll")
public class RoomSelectAll extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String condition=request.getParameter("room");
        List<Room> rooms = service.selectAll();
        //System.out.println(rooms);
        request.setAttribute("rooms",rooms);
        if ("change".equals(condition)){
            request.getRequestDispatcher("/changeRoom.jsp").forward(request,response);
        }else {
            request.getRequestDispatcher("/roomPage.jsp").forward(request, response);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
