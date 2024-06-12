package com.xxx.web;

import com.xxx.pojo.RoomStatus;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.List;

@WebServlet("/TakenSelectAllServlet")
public class TakenSelectAllServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<RoomStatus> rs = service.select();
        request.setAttribute("rs",rs);
        request.getRequestDispatcher("/takenRoom.jsp").forward(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
