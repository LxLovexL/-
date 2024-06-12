<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false"%>
<html>
<head>
    <title>Title</title>
</head>
<body>
<form  action="deleteTakenServlet" method="post" id="outForm">
    <input type="hidden" name="id" value="${rs.id}">
    <p>门牌号：<input id="roomDoor" name="roomDoor" readonly="readonly" type="text" value="${rs.roomDoor}"></p>
    <p>旅客姓名：<input id="guestName" name="guestName" readonly="readonly" type="text" value="${rs.guestName}"></p>
    <p>身份证：<input id="guestId" name="guestId" readonly="readonly" type="text" value="${rs.guestId}"></p>
    <p>电话号码：<input id="guestPhone" name="guestPhone" readonly="readonly" type="text" value="${rs.guestPhone}"></p>
    <p>入住时间：<input id="inTime" name="inTime" readonly="readonly" type="text" value="${rs.inTime}"></p>
    <p>退房时间：<input id="outTime" name="outTime" type="datetime-local" ></p>
    <input type="submit" class="button" value="退房">
    <input type="button" value="返回" id="back">
</form>
<script>
    document.getElementById("back").onclick=function (){
        location.href="/hotel/TakenSelectAllServlet"
    }
</script>
</body>
</html>
