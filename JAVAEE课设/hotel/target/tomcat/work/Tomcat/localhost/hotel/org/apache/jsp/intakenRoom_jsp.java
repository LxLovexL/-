/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/7.0.47
 * Generated at: 2023-12-06 15:17:42 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class intakenRoom_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private javax.el.ExpressionFactory _el_expressionfactory;
  private org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public void _jspInit() {
    _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
    _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
        throws java.io.IOException, javax.servlet.ServletException {

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("\r\n");
      out.write("\r\n");
      out.write("<html>\r\n");
      out.write("<head>\r\n");
      out.write("    <meta charset=\"UTF-8\">\r\n");
      out.write("    <title>房间入住</title>\r\n");
      out.write("</head>\r\n");
      out.write("<body>\r\n");
      out.write("<h3>房间入住</h3>\r\n");
      out.write("<form  action=\"/hotel/RoomStatusServlet\" method=\"post\" id=\"takenForm\"  onsubmit=\"return takeIn()\">\r\n");
      out.write("    <p>房间类型：<input id=\"style\" name=\"style\" value=\"");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${room.style}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null, false));
      out.write("\"></p>\r\n");
      out.write("    <p>门牌号：<input id=\"door\" name=\"door\" value=\"");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${room.door}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null, false));
      out.write("\"></p>\r\n");
      out.write("    <p>旅客姓名：<input id=\"guestName\" name=\"guestName\" type=\"text\"></p>\r\n");
      out.write("    <p>身份证：<input id=\"guestId\" name=\"guestId\" type=\"text\"></p>\r\n");
      out.write("    <p>电话号码：<input id=\"guestPhone\" name=\"guestPhone\" type=\"text\"></p>\r\n");
      out.write("    <p>入住时间：<input id=\"inTime\" name=\"inTime\" type=\"datetime-local\"></p>\r\n");
      out.write("    <input type=\"submit\" class=\"button\" value=\"入住\">\r\n");
      out.write("    <input type=\"button\" value=\"返回\" id=\"back\" >\r\n");
      out.write("</form>\r\n");
      out.write("<script>\r\n");
      out.write("    function takeIn(){\r\n");
      out.write("        var style=document.getElementById(\"style\").value;\r\n");
      out.write("        var door=document.getElementById(\"door\").value;\r\n");
      out.write("        var guestName=document.getElementById(\"guestName\").value;\r\n");
      out.write("        var guestId=document.getElementById(\"guestId\").value;\r\n");
      out.write("        var guestPhone=document.getElementById(\"guestPhone\").value;\r\n");
      out.write("        var inTime=document.getElementById(\"inTime\").value;\r\n");
      out.write("        if (style===\"\"||door===\"\"||guestName===\"\"||guestId===\"\"||inTime===\"\"||guestPhone===\"\"){\r\n");
      out.write("            alert(\"信息不能为空\");\r\n");
      out.write("            return false;\r\n");
      out.write("        }\r\n");
      out.write("        return  true;\r\n");
      out.write("    }\r\n");
      out.write("    document.getElementById(\"back\").onclick = function (){\r\n");
      out.write("        location.href = \"/hotel/RoomSelectAll\";\r\n");
      out.write("    }\r\n");
      out.write("</script>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</body>\r\n");
      out.write("</html>\r\n");
      out.write("</body>\r\n");
      out.write("</html>\r\n");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try { out.clearBuffer(); } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
