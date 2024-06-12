package com.xxx.web;

import com.xxx.pojo.RoomStatus;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet("/RoomStatusServlet")
public class RoomStatusServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        String style = request.getParameter("style");
        String door = request.getParameter("door");
        String guestName = request.getParameter("guestName");
        String guestId = request.getParameter("guestId");
        String guestPhone = request.getParameter("guestPhone");
        String inTime = request.getParameter("inTime");
        RoomStatus roomStatus = new RoomStatus();
        roomStatus.setRoomDoor(door);
        roomStatus.setRoomStyle(style);
        roomStatus.setGuestName(guestName);
        roomStatus.setGuestId(guestId);
        roomStatus.setGuestPhone(guestPhone);
        roomStatus.setInTime(inTime);
        service.addInRoom(roomStatus);
        service.updateStatus(door);
        request.getRequestDispatcher("/TakenSelectAllServlet").forward(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
