package social;
import java.lang.System;

public class Post {
    private String author;
    private String text;
    private String pid;
    private long time;

    public Post(String author, String text, String pid) {
        this.author = author;
        this.text = text;
        this.pid = pid;
    }

    public String getAuthor() {
        return author;
    }
    public void setAuthor(String author) {
        this.author = author;
    }
    public String getText() {
        return text;
    }
    public void setText(String text) {
        this.text = text;
    }
    public String getPid() {
        return pid;
    }
    public void setPid(String pid) {
        this.pid = pid;
    }
    public long getTime() {
        return time;
    }
    public void setTime(long time) {
        this.time = System.currentTimeMillis();
    }
}
