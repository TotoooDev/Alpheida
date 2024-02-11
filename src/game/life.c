#include <game/life.h>
#include <engine/platform/fs.h>
#include <engine/app.h>
#include <engine/log.h>

void life_draw_function(Sprite* sprite, Renderer* renderer) {
    Life* life = (Life*)sprite->user_pointer;


    renderer_render_text(renderer, life->font, "health: ", color_black(), (vec2){ 0.0f, sprite->pos[1] }, 1.0f);
    if (life->shrimp->hp <= 0) {
        renderer_render_text(renderer, life->font, "u dead :(", color_black(), (vec2){ 128.0f, sprite->pos[1] }, 1.0f);
        return;
    }
    
    f32 x = 128.0f;
    for (u32 i = 0; i < life->shrimp->hp; i++) {
        renderer_render_texture(renderer, life->heart_texture, (vec2){ x, sprite->pos[1] + 10.0f }, (vec2){ 32.0f, 32.0f }, 0.0f);
        x += 32.0f;
    }
}

Life* life_new(Shrimp* shrimp, Scene* scene) {
    Life* life = (Life*)malloc(sizeof(Life));
    
    life->sprite = sprite_new((vec2){ 0.0f, window_get_height(app_get_window()) - 40.0f }, (vec2){ 1.0f, 1.0f }, NULL);
    life->sprite->draw_function = life_draw_function;
    life->sprite->user_pointer = life;
    
    life->heart_texture = texture_new(fs_get_path_romfs("images/heart.png"));
    life->shrimp = shrimp;
    life->font = font_new(fs_get_path_romfs("font.ttf"), 32);
    life->scene = scene;

    scene_add_sprite(scene, life->sprite);
    
    return life;
}

void life_delete(Life* life) {
    font_delete(life->font);
    texture_delete(life->heart_texture);
    scene_remove_sprite(life->scene, life->sprite);
    free(life);
}
