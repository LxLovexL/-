<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>已入住房间</title>
</head>
<body>
<input type="button" value="所有客房界面" id="back"><br>

<form  action="/hotel/TakenSelectByServlet" method="post" id="takenForm">
    <p>门牌号：<input id="door" name="door" type="text"></p>
    <p>旅客姓名：<input id="guestName" name="guestName" type="text"></p>
    <p>身份证：<input id="guestId" name="guestId" type="text"></p>
    <p>电话号码：<input id="guestPhone" name="guestPhone" type="text"></p>
    <p>入住时间：<input id="inTime" name="inTime" type="text"></p>
    <input type="submit" class="button" value="查询">
    <input type="button" value="显示所有" id="selectAll">
</form>

<hr>
<table border="1" cellspacing="0" width="80%">
    <tr>
        <th>序号</th>
        <th>房间样式</th>
        <th>门号</th>
        <th>旅客姓名</th>
        <th>身份证</th>
        <th>电话号码</th>
        <th>入住时间</th>
        <th>操作</th>

    </tr>


    <c:forEach items="${rs}" var="rs" varStatus="status">
        <tr align="center">
            <td>${status.count}</td>
            <td>${rs.roomStyle}</td>
            <td>${rs.roomDoor}</td>
            <td>${rs.guestName}</td>
            <td>${rs.guestId}</td>
            <td>${rs.guestPhone}</td>
            <td>${rs.inTime}</td>
                <%--  <td><a href="/hotel/selectByIdServlet?id=${brand.id}">修改</a> <a href="#">删除</a> </td>--%>
            <td><a href="outRoomServlet?id=${rs.id}">退房</a><a href="changeSelectServlet?door=${rs.roomDoor}">换房</a></td>
        </tr>
    </c:forEach>
</table>



<script>
    document.getElementById("back").onclick=function (){
        location.href="/hotel/RoomSelectAll"
    }
    document.getElementById("selectAll").onclick=function (){
        location.href="/hotel/TakenSelectAllServlet"
    }
</script>
</body>
</html>
