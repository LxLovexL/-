<%@ page contentType="text/html;charset=UTF-8" language="java"  isELIgnored="false"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>住房备份</title>
</head>
<body>
<input type="button" value="所有客房界面" id="back"><br>
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
        <th>退房时间</th>

    </tr>

    <c:forEach items="${bs}" var="bs" varStatus="status">
        <tr align="center">
            <td>${status.count}</td>
            <td>${bs.roomStyle}</td>
            <td>${bs.roomDoor}</td>
            <td>${bs.guestName}</td>
            <td>${bs.guestId}</td>
            <td>${bs.guestPhone}</td>
            <td>${bs.inTime}</td>
            <td>${bs.outTime}</td>
        </tr>
    </c:forEach>
</table>

<script>
    document.getElementById("back").onclick=function (){
        location.href="/hotel/RoomSelectAll"
    }
</script>
</body>
</html>
