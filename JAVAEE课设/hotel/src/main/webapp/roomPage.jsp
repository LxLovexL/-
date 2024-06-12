<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<a href="TakenSelectAllServlet">查看已入住房间</a>
<a href="backupServlet">查看住房记录</a>

<form action="/hotel/RoomSelectServlet" id="form" method="post">
    <input type="hidden" name="room" value="room">
    房间样式<input type="text" name="style" id="style">
    房门号<input type="text" name="door" id="door">
    价格<input type="text" name="highPrice" id="highPrice">
    是否空闲<input type="text" name="status" id="status">
    <input type="submit" class="button" value="查询">
    <input type="button" value="显示所有" id="selectAll">
</form>


<hr>
<table border="1" cellspacing="0" width="80%" id="table">
    <tr>
        <th>序号</th>
        <th>房间样式</th>
        <th>门号</th>
        <th>价格</th>
        <th>备注</th>
        <th>状态</th>
        <th>操作</th>
    </tr>

    <c:forEach items="${rooms}" var="room" varStatus="status">
        <tr align="center">
                <%--<td>${brand.id}</td>--%>
            <td>${status.count}</td>
            <td>${room.style}</td>
            <td>${room.door}</td>
            <td>${room.price}</td>
            <td>${room.others}</td>
            <c:if test="${room.status == 0}">
                <td>空闲</td>
            </c:if>
            <c:if test="${room.status == 1}">
                <td>已入住</td>
            </c:if>
          <%--  <td><a href="/hotel/selectByIdServlet?id=${brand.id}">修改</a> <a href="#">删除</a> </td>--%>

            <td><a href="/hotel/intakenRoomServlet?door=${room.door}" onclick="return checkTaken(${room.status})">入住</a></td>
        </tr>

    </c:forEach>

</table>

<script>
    document.getElementById("add").onclick = function (){
        location.href = "/hotel/addRoom.jsp";
    }
    document.getElementById("selectAll").onclick = function (){
        var dataToSend = "room";
        location.href = "/hotel/RoomSelectAll?room="+ encodeURIComponent(dataToSend);
        /*location.href = "/hotel/RoomSelectAll";*/
    }
    function checkTaken(status){
        if(status==1){
            alert("房间已被占用，无法入住");
            return false;
        }
        return true;
    }


</script>
</body>
</html>