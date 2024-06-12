package com.xxx.web;

import com.xxx.pojo.Backup;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.List;

@WebServlet("/backupServlet")
public class backupServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<Backup> backups = service.selectBackup();
        request.setAttribute("bs",backups);
        request.getRequestDispatcher("/backup.jsp").forward(request,response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
