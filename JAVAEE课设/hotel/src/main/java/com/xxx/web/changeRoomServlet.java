package com.xxx.web;

import com.xxx.pojo.RoomStatus;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@WebServlet("/changeRoomServlet")
public class changeRoomServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        String style = request.getParameter("style");
        String door1 = request.getParameter("door1");
        String door2 = request.getParameter("door2");
        String id=request.getParameter("id");
        style=new String(style.getBytes(StandardCharsets.ISO_8859_1),StandardCharsets.UTF_8);
        System.out.println(style);
        RoomStatus rs = new RoomStatus();
        rs.setRoomStyle(style);
        rs.setRoomDoor(door1);
        rs.setDoor(door2);
        service.updateInRoom(rs);
        service.updateStatus(door2);
        service.updateStatus2(door1);
        request.getRequestDispatcher("/TakenSelectAllServlet").forward(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
