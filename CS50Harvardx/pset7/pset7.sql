-- MySQL dump 10.13  Distrib 5.5.46, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.46-0ubuntu0.14.04.2-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL,
  `datetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `symbol` varchar(225) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `buysell` varchar(225) COLLATE utf8_unicode_ci NOT NULL,
  `price` decimal(10,0) unsigned NOT NULL,
  KEY `datetime` (`datetime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (6,'2015-11-09 00:59:43','FREE',3,'BUY',0),(6,'2015-11-09 01:15:02','r',13,'BUY',919),(6,'2015-11-09 01:19:30','e',12,'BUY',382),(6,'2015-11-09 01:19:41','ee',3,'BUY',118),(6,'2015-11-09 01:34:36','f',13,'BUY',186),(6,'2015-11-09 01:34:50','GLD',12,'BUY',1253),(6,'2015-11-09 01:35:03','f',13,'SELL',186),(6,'2015-12-09 04:23:29','g',1,'BUY',25),(6,'2015-12-09 04:33:05','e',1,'BUY',31),(6,'2015-12-09 04:34:27','g',1,'SELL',25),(6,'2015-12-09 04:34:40','t',1,'SELL',34),(6,'2015-12-09 04:34:51','i',30,'BUY',122);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) NOT NULL,
  `symbol` varchar(225) COLLATE utf8_unicode_ci NOT NULL,
  `shares` decimal(10,0) NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (1,'FREE',10),(2,'FREE',10),(3,'FREE',10),(4,'FREE',10),(5,'FREE',10),(6,'E',1),(6,'GLD',12),(6,'I',30),(7,'FREE',10),(8,'FREE',10),(9,'FREE',10),(10,'FREE',10),(11,'FREE',10),(12,'FREE',10),(13,'FREE',10),(14,'FREE',10),(15,'FREE',10);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `hash` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'belindazeng','$1$50$oxJEDBo9KDStnrhtnSzir0',1000.0000),(2,'caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',1000.0000),(3,'jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',1000.0000),(4,'malan','$1$50$lJS9HiGK6sphej8c4bnbX.',1000.0000),(5,'rob','$1$HA$l5llES7AEaz8ndmSo5Ig41',1000.0000),(6,'skroob','$1$d4Qm..XW$dWqWgzcjfHEBndokCIhzZ/',144537.1642),(7,'zamyla','$1$50$uwfqB45ANW.9.6qaQ.DcF.',1000.0000),(8,'Tjitske','$1$SInjj3Mj$yKoClVJS8jAqnFTeJNdgi0',1000.0000),(9,'Marten','$1$cQy2howf$75qbG/FPkAIxQPvWdr701/',1000.0000),(10,'test','$1$0wEBkK1y$DvubjMuh19Q3OKodYRpbj/',1000.0000),(11,'index','$1$srZs1m6a$1HYXsHeDPX3tgAbENuvT9.',1000.0000),(13,'test2','$1$RMAYwSzx$YNs.7/hWv7Fndi82sXMbn/',1000.0000),(14,'test3','$1$0wQbhEtb$O0mL0eRHXquYCtsE/oD7G1',1000.0000),(15,'tata','$1$6J0LxA48$i88KD44jVF8AozKlY3Ffu0',1000.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-12-09  5:46:19
