package com.xxx.web;

import com.xxx.pojo.RoomStatus;
import com.xxx.util.service.RoomService;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet("/TakenSelectByServlet")
public class TakenSelectByServlet extends HttpServlet {
    RoomService service = new RoomService();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Map map=new HashMap();

        request.setCharacterEncoding("UTF-8");

        String door = request.getParameter("door");
        String guestName = request.getParameter("guestName");
        String guestId = request.getParameter("guestId");
        String guestPhone = request.getParameter("guestPhone");
        String inTime = request.getParameter("inTime");

        if (door!=null&&!door.isEmpty()){
            door="%"+door+"%";
            map.put("roomDoor",door);
        }
        if (guestName!=null&&!guestName.isEmpty()){
            map.put("guestName",guestName);
        }
        if (guestId!=null&&!guestId.isEmpty()){
            map.put("guestId",guestId);
        }
        if (guestPhone!=null&&!guestPhone.isEmpty()){
            map.put("guestPhone",guestPhone);
        }
        if (inTime!=null&&!inTime.isEmpty()){
            map.put("inTime",inTime);
        }

        List<RoomStatus> rs = service.selectByCondition2(map);
      //  System.out.println(rs);
        request.setAttribute("rs",rs);
        request.getRequestDispatcher("/takenRoom.jsp").forward(request,response);

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
