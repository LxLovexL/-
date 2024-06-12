package com.xxx.web;

import com.xxx.pojo.Room;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet("/RoomSelectServlet")
public class RoomSelectServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Map map=new HashMap();

        request.setCharacterEncoding("UTF-8");
        String condition=request.getParameter("room");
        System.out.println(condition);
        String style=request.getParameter("style");
        String door=request.getParameter("door");
        String highPrice=request.getParameter("highPrice");
        String status= request.getParameter("status");

        if (style!=null&&!style.isEmpty()){
            style="%"+style+"%";
            map.put("style",style);
        }

        if (door!=null&&!door.isEmpty()){
            map.put("door",door);
        }

        if (highPrice!=null&&!highPrice.isEmpty()){

            map.put("highPrice",Integer.parseInt(highPrice));
        }

        if (status!=null&&!status.isEmpty()){
            map.put("status",status);
        }

       // System.out.println(map);
        List<Room> rooms = service.selectByCondition(map);
    //    System.out.println(rooms);
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
