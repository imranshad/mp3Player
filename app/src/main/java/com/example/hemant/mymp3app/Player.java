package com.example.hemant.mymp3app;

import android.content.Intent;
import android.media.MediaPlayer;
import android.net.Uri;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;

import java.io.File;
import java.util.ArrayList;


public class Player extends ActionBarActivity implements View.OnClickListener{
static MediaPlayer mp;  int position;
    ArrayList<File> mySongs;
    SeekBar  sb; Uri u;
    Button  btPlay,btFF,btFB,btNxt,btPv;
   Thread updateSeekBar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_player);

        btPlay=(Button)findViewById(R.id.btPlay);
        btFF=(Button)findViewById(R.id.btFF);
        btFB=(Button)findViewById(R.id.btFB);
        btNxt=(Button)findViewById(R.id.btNxt);
        btPv=(Button)findViewById(R.id.btPv);

        btPlay.setOnClickListener(this);
        btNxt.setOnClickListener(this);
        btFB.setOnClickListener(this);
        btFF.setOnClickListener(this);
        btPv.setOnClickListener(this);

        sb =(SeekBar)findViewById(R.id.seekBar);
        updateSeekBar= new Thread(){
            public void run(){
                int totalDuration=mp.getDuration();
                int currentPosition=0;
                sb.setMax(totalDuration);
                while (currentPosition < totalDuration){
                    try{
                        sleep(500);
                        currentPosition=mp.getCurrentPosition();
                        sb.setProgress(currentPosition);
                    }catch(Exception r){
                        r.printStackTrace();
                    }

                }
            }
        };

        if(mp!=null){
            mp.start();
            mp.release();
        }

       Intent i = getIntent();
       Bundle b= i.getExtras();
        mySongs = (ArrayList)b.getParcelableArrayList("songlist");
        position = b.getInt("pos",0);

       u = Uri.parse(mySongs.get(position).toString());
    mp= MediaPlayer.create(getApplicationContext(),u);
        mp.start();
        sb.setMax(mp.getDuration());
        updateSeekBar.start();

        sb.setOnSeekBarChangeListener( new SeekBar.OnSeekBarChangeListener(){
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                     mp.seekTo(seekBar.getProgress());
            }
        });
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_player, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onClick(View v) {
        int id= v.getId();
        switch (id) {
             case R.id.btPlay:
                   if(mp.isPlaying())
                   {   btPlay.setText(">");
                       mp.pause();
                   }else{
                       btPlay.setText("||");
                       mp.start();
                   }
                break;

            case R.id.btFF:
                mp.seekTo(mp.getCurrentPosition()+5000);
                break;

            case R.id.btFB:
                mp.seekTo(mp.getCurrentPosition()-5000);
                break;

            case R.id.btNxt:
                mp.stop();
                mp.release();
                position= (position+1)%mySongs.size();
                 u = Uri.parse(mySongs.get((position)).toString());
                mp= MediaPlayer.create(getApplicationContext(),u);
                mp.start();
                break;
            case R.id.btPv:
                mp.stop();
                mp.release();
                position= (position-1> 0)? mySongs.size()-1:position-1;
              /*  if(position-1<0)
                {
                    position=mySongs.size()-1;
                }else{

                    position=position-1;
                }*/
                 u = Uri.parse(mySongs.get((position)).toString());
                mp= MediaPlayer.create(getApplicationContext(),u);
                mp.start();
                break;

        }
      }
}
