CREATE OR REPLACE PACKAGE SCHOOL_API IS 
PROCEDURE REMOVE_STUDENT(ST_ID NUMBER);
END SCHOOL_API;


CREATE OR REPLACE PACKAGE BODY SCHOOL_API IS

PROCEDURE REMOVE_STUDENT(ST_ID NUMBER) IS
MY_EXCEPT EXCEPTION;
BEGIN
DELETE
FROM STUDENT1
WHERE RNO=ST_ID;
EXCEPTION
WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('NO TUPLE WITH THAT ROLL NUMBER EXISTS');
END REMOVE_STUDENT;

END SCHOOL_API;


SET SERVEROUTPUT ON;
ACCEPT N1 PROMPT 'ENTER THE STUDENT ROLL NUMBER TO BE DELETED'
DECLARE
STID NUMBER:=&N1;
MY_EXCEPT EXCEPTION;
BEGIN
SCHOOL_API.REMOVE_STUDENT(STID);
EXCEPTION
WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('NO TUPLE WITH THAT ROLL NUMBER EXISTS');
END;
