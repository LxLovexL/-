<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false" %>
<html>
<head>
    <title>换房</title>
    <meta charset="UTF-8">
</head>
<body>

<form action="/hotel/RoomSelectServlet" id="form" method="post" >
    <input type="hidden" name="room" value="change">
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
            <th>选择</th>
        </tr>

        <c:forEach items="${rooms}" var="room" varStatus="status">
            <tr align="center">
                <td>${status.count}</td>
                <td>${room.style}</td>
                <td>${room.door}</td>
                <td>${room.price}</td>
                <td>${room.others}</td>
                <c:if test="${room.status == 0}">
                    <td><a href="/hotel/changeRoomServlet?style=${room.style}&door2=${room.door}&door1=${doors}
                    &id=${room.id}"
                           onclick="return changeRoom()"> 换房</a></td>
                </c:if>
                <c:if test="${room.status == 1}">
                    <td>已入住,无法换房</td>
                </c:if>
            </tr>
        </c:forEach>
    </table>
    <input type="button" value="返回" id="back">


<script>
    function changeRoom(){
        var result = confirm("是否换房？");
        if (result) {
           return true;
        } else {
            alert("取消了换房")
            return false;
        }
    }
    document.getElementById("back").onclick=function (){
        location.href="/hotel/TakenSelectAllServlet"
    }

    document.getElementById("selectAll").onclick = function (){
        var dataToSend = "change";
        location.href = "/hotel/RoomSelectAll?room="+ encodeURIComponent(dataToSend);
    }
</script>
</body>
</html>
