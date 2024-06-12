/*
 Navicat Premium Data Transfer

 Source Server         : localhost_3306
 Source Server Type    : MySQL
 Source Server Version : 80035 (8.0.35)
 Source Host           : localhost:3306
 Source Schema         : hotel

 Target Server Type    : MySQL
 Target Server Version : 80035 (8.0.35)
 File Encoding         : 65001

 Date: 25/12/2023 14:55:13
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `admin_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NOT NULL,
  `admin_number` int NOT NULL,
  `admin_phone` int NULL DEFAULT NULL,
  `admin_idnumber` int NULL DEFAULT NULL,
  `admin_accounts` int NULL DEFAULT NULL,
  `admin_password` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 2 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES (1, 'zhangsan', 1, NULL, NULL, 12345, '12345');

-- ----------------------------
-- Table structure for backup
-- ----------------------------
DROP TABLE IF EXISTS `backup`;
CREATE TABLE `backup`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `room_style` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `room_door` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_id` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_phone` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `in_time` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `out_time` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 41 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of backup
-- ----------------------------
INSERT INTO `backup` VALUES (25, '豪华大床房', '101', '', '', '', '', NULL);
INSERT INTO `backup` VALUES (26, '豪华大床房', '101', 'z', '123', '123', '213', NULL);
INSERT INTO `backup` VALUES (27, '豪华大床房', '101', '', '', '', '', '2023-11-29');
INSERT INTO `backup` VALUES (28, '豪华大床房', '101', 'z', '123', '123', '213', '2023-11-30');
INSERT INTO `backup` VALUES (29, '豪华大床房', '101', '', '', '', '', '2023-11-29');
INSERT INTO `backup` VALUES (30, '豪华大床房', '101', 'z', '123', '123', '213', '2023-12-01');
INSERT INTO `backup` VALUES (31, 'Pluots', '279', '1', '1', '1', '1', '2023-12-01');
INSERT INTO `backup` VALUES (32, '豪华大床房', '101', '', '', '', '', '2023-11-30');
INSERT INTO `backup` VALUES (33, '豪华大床房', '101', '', '', '', '', '2023-12-01');
INSERT INTO `backup` VALUES (34, 'abc', '101', 'lisi', '12345', '12345', '1234', '2023-11-29');
INSERT INTO `backup` VALUES (35, 'abc', '101', 'lisi', '12345', '12345', '1234', '2023-11-29');
INSERT INTO `backup` VALUES (36, '豪华大床房', '101', '张三', '123', '123', '123', '2023-12-16');
INSERT INTO `backup` VALUES (37, '双人房', '102', '李四', '123', '123', '123', '2023-12-07T02:21');
INSERT INTO `backup` VALUES (38, '双人房', '102', '王五', '1234', '1234', '2023-12-10T17:53', '2023-12-11T17:54');
INSERT INTO `backup` VALUES (39, 'Strawberry core', '869', '李四', '1234', '124', '2023-12-02T17:53', '2023-12-02T19:31');
INSERT INTO `backup` VALUES (40, '双人房', '102', '1', '1', '1', '2023-12-17T18:40', '2023-12-24T13:44');

-- ----------------------------
-- Table structure for guest
-- ----------------------------
DROP TABLE IF EXISTS `guest`;
CREATE TABLE `guest`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `guest_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_age` int NULL DEFAULT NULL,
  `guest_phone` int NULL DEFAULT NULL,
  `guest_idnumber` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of guest
-- ----------------------------

-- ----------------------------
-- Table structure for room
-- ----------------------------
DROP TABLE IF EXISTS `room`;
CREATE TABLE `room`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `style` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `door` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `price` int NULL DEFAULT NULL,
  `others` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `status` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of room
-- ----------------------------
INSERT INTO `room` VALUES (1, '豪华大床房', '101', 100, '设备齐全', 0);
INSERT INTO `room` VALUES (2, 'Strawberry core', '869', 61, 'G16o0vqtzk', 1);
INSERT INTO `room` VALUES (3, 'Pluots', '279', 63, 'iymdMqYG6r', 0);
INSERT INTO `room` VALUES (4, '双人房', '102', 80, '无', 0);

-- ----------------------------
-- Table structure for room_status
-- ----------------------------
DROP TABLE IF EXISTS `room_status`;
CREATE TABLE `room_status`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `room_style` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `room_door` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_id` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `guest_phone` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `in_time` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  `out_time` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_bin NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 33 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of room_status
-- ----------------------------
INSERT INTO `room_status` VALUES (32, 'Strawberry core', '869', '李四', '12345', '12345', '2023-12-10T22:04', NULL);

SET FOREIGN_KEY_CHECKS = 1;
