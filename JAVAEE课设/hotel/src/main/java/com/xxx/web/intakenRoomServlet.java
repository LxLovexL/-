package com.xxx.web;

import com.xxx.pojo.Room;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

//将入住信息添加到表中
@WebServlet("/intakenRoomServlet")
public class intakenRoomServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String door = request.getParameter("door");
        Room room = service.selectByDoor(door);
        request.setAttribute("room",room);
        request.getRequestDispatcher("/intakenRoom.jsp").forward(request,response);

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
