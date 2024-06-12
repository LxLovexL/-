<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>房间入住</title>
</head>
<body>
<h3>房间入住</h3>
<form  action="/hotel/RoomStatusServlet" method="post" id="takenForm"  onsubmit="return takeIn()">
    <p>房间类型：<input id="style" name="style" value="${room.style}"></p>
    <p>门牌号：<input id="door" name="door" value="${room.door}"></p>
    <p>旅客姓名：<input id="guestName" name="guestName" type="text"></p>
    <p>身份证：<input id="guestId" name="guestId" type="text"></p>
    <p>电话号码：<input id="guestPhone" name="guestPhone" type="text"></p>
    <p>入住时间：<input id="inTime" name="inTime" type="datetime-local"></p>
    <input type="submit" class="button" value="入住">
    <input type="button" value="返回" id="back" >
</form>

<script>
    function takeIn(){
        var style=document.getElementById("style").value;
        var door=document.getElementById("door").value;
        var guestName=document.getElementById("guestName").value;
        var guestId=document.getElementById("guestId").value;
        var guestPhone=document.getElementById("guestPhone").value;
        var inTime=document.getElementById("inTime").value;
        if (style===""||door===""||guestName===""||guestId===""||inTime===""||guestPhone===""){
            alert("信息不能为空");
            return false;
        }
        return  true;
    }
    document.getElementById("back").onclick = function (){
        location.href = "/hotel/RoomSelectAll";
    }
</script>



</body>
</html>
</body>
</html>
