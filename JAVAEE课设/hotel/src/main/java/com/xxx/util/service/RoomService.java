package com.xxx.util.service;

import com.xxx.mapper.RoomMapper;
import com.xxx.pojo.Backup;
import com.xxx.pojo.Room;
import com.xxx.pojo.RoomStatus;
import com.xxx.util.SqlSessionFactoryUtils;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.util.List;
import java.util.Map;

public class RoomService {
    SqlSessionFactory factory = SqlSessionFactoryUtils.getSqlSessionFactory();
    /*
    * 查询所有房间
    * */
    public List<Room> selectAll(){
        //调用RM中的selectAll
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);

        //调用方法
        List<Room> rooms = mapper.selectAll();

        sqlSession.close();

        return rooms;
    }

    public List<Backup> selectBackup(){
        //调用RM中的selectAll
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);

        //调用方法
        List<Backup> backups = mapper.selectBackup();

        sqlSession.close();

        return backups;
    }



    public  List<Room> selectByCondition(Map map){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        List<Room> rooms = mapper.selectByCondition(map);

        sqlSession.close();

        return rooms;
    }

    public List<RoomStatus> selectByCondition2(Map map){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        List<RoomStatus> rs = mapper.selectByCondition2(map);

        sqlSession.close();

        return rs;
    }

    public  Room selectByDoor(String door){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        Room room = mapper.selectByDoor(door);
        sqlSession.close();

        return room;
    }

    public RoomStatus selectById(Integer id){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
       RoomStatus rs = mapper.selectById(id);

        sqlSession.close();

        return rs;
    }

    public  void  addInRoom(RoomStatus roomStatus){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
         mapper.addInRoom(roomStatus);
         sqlSession.commit();
        sqlSession.close();
    }

    public  void  addBackup(RoomStatus roomStatus){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        mapper.addBackup(roomStatus);
        sqlSession.commit();
        sqlSession.close();
    }

    public  List<RoomStatus> select(){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        List<RoomStatus> roomStatuses = mapper.select();
        sqlSession.close();

        return roomStatuses;
    }

    public  void  updateStatus(String door){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        mapper.updateStatus(door);
        sqlSession.commit();
        sqlSession.close();
    }

    public  void  updateStatus2(String door){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        mapper.updateStatus2(door);
        sqlSession.commit();
        sqlSession.close();
    }

    public  void  updateInRoom(RoomStatus roomStatus){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        mapper.updateInRoom(roomStatus);
        sqlSession.commit();
        sqlSession.close();
    }

    public void deleteTaken(Integer id){
        //获取对应的SqlSession
        SqlSession sqlSession = factory.openSession();
        //获取RM
        RoomMapper mapper = sqlSession.getMapper(RoomMapper.class);
        //调用方法
        mapper.deleteTaken(id);
        sqlSession.commit();
        sqlSession.close();
    }

}
