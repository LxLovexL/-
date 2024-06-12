package com.xxx.web;

import com.xxx.pojo.RoomStatus;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet("/deleteTakenServlet")
public class deleteTakenServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        String id = request.getParameter("id");
        String outTime = request.getParameter("outTime");
        RoomStatus rs = service.selectById(Integer.parseInt(id));
        rs.setOutTime(outTime);
        String door= rs.getRoomDoor();
        service.addBackup(rs);
        service.updateStatus2(door);
        service.deleteTaken(Integer.parseInt(id));
        request.getRequestDispatcher("/TakenSelectAllServlet").forward(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
