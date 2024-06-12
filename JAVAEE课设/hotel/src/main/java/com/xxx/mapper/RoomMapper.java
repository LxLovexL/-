package com.xxx.mapper;

import com.xxx.pojo.Backup;
import com.xxx.pojo.Room;
import com.xxx.pojo.RoomStatus;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface RoomMapper {

    List<Room> selectAll ();

    List<RoomStatus> select();

    List<Room> selectByCondition(Map map);

    List<RoomStatus> selectByCondition2(Map map);

    List<Backup> selectBackup();
    Room selectByDoor(String door);

    RoomStatus selectById(Integer id);

    void addInRoom(RoomStatus roomStatus);

    void addBackup(RoomStatus roomStatus);

    void updateInRoom(RoomStatus roomStatus);

    void updateStatus(String door);

    void updateStatus2(String door);

    void deleteTaken(Integer id);
}
